#include "backgroundmusic.h"

backgroundmusic::backgroundmusic()
{


    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl("qrc:/res/sound/bg_2.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    sf=new QMediaPlayer;
    player = new QMediaPlayer;
    player->setPlaylist(playlist);
    player->setVolume(50);
    player->play();
}
void backgroundmusic::pickup()
{
    sf->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/git/Magic_Tower/res/sound/cursor move_1.wav"));
    sf->setVolume(50);
    sf->play();
}
void backgroundmusic::opendoor()
{

    sf->setMedia(QUrl::fromLocalFile("/home/divik/Desktop/git/Magic_Tower/res/sound/fight end.wav"));
    sf->setVolume(50);
    sf->play();
}
