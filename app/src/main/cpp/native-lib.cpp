#include <jni.h>
#include <memory>
#include <cstdio>
#include <libtorrent/settings_pack.hpp>
#include <libtorrent/session.hpp>
#include "libtorrent/version.hpp"
#include "libtorrent/torrent_info.hpp"

extern "C"
{
JNIEXPORT jstring JNICALL
Java_in_canews_libtorrentexample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    const char* hello = libtorrent::version();
    return env->NewStringUTF(hello);
}

void start(char* argv[]){
    libtorrent::session s;
    libtorrent::add_torrent_params p;
    p.save_path = "./";
    p.ti = std::make_shared<libtorrent::torrent_info>(argv[1]);
    s.add_torrent(p);

    // wait for the user to end
    char a;
    int ret = std::scanf("%c\n", &a);
    (void)ret; // ignore
    return;
}


}