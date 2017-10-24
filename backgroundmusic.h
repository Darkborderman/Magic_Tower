#ifndef BACKGROUNDMUSIC_H
#define BACKGROUNDMUSIC_H

#include<QtMultimedia/QMediaPlayer>
#include<QMediaPlaylist>

class backgroundmusic
{
public:
    backgroundmusic();
    QMediaPlayer *player,*sf;
    void pickup();
    void opendoor();
};

#endif // BACKGROUNDMUSIC_H
