#include "backgroundmusic.h"
#include<QMediaPlaylist>
backgroundmusic::backgroundmusic()
{
    sf=new QMediaPlayer;
   // player->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/git/Magic_Tower/res/sound/bg_2.wav"));

    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl("qrc:/res/sound/bg_2.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(50);
    player->play();
}
