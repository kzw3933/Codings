#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>

#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include "bomb.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

public:
    // 初始化场景
    void initScene();
    // 启动游戏
    void playGame();
    // 更新所有游戏元素的坐标
    void updatePosition();

    // 重载绘制到屏幕中
    void paintEvent(QPaintEvent *);
    // 重载鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    // 敌机出场
    void enemyToScene();
    // 碰撞检测
    void collisionDetection();
public:
    // 地图对象
    Map m_map;
    // 飞机对象
    HeroPlane m_hero;
    // 定时器
    QTimer m_Timer;
    // 敌机数组
    EnemyPlane m_enemys[ENEMY_NUM];
    // 敌机出场间隔记录
    int m_recorder;
    // 爆炸数组
    Bomb m_bombs[BOMB_NUM];

};
#endif // MAINSCENE_H
