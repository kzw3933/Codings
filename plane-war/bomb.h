#ifndef BOMB_H
#define BOMB_H

#include <QVector>
#include <QPixmap>

class Bomb
{
public:
    Bomb();
public:
    // 更新信息
    void updateInfo();
public:
    // 保存爆炸资源数组
    QVector<QPixmap> m_pixArr;
    // 爆炸位置
    int m_X;
    int m_Y;
    // 爆炸状态
    bool m_Free;
    // 爆炸切图的时间间隔
    int m_Recorder;
    // 爆炸加载的图片索引
    int m_index;
};

#endif // BOMB_H
