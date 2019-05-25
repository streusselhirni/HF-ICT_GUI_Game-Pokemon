//
// Created by Nicolas Haenni on 2019-05-18.
//

#ifndef HARAMBE_THREAD_H
#define HARAMBE_THREAD_H


#include <QThread>

class Thread : public QThread
{
    Q_OBJECT;
private:
    bool active;
    void run() override;
public:
    Thread();

    void pause();

    void resume();

    bool isActive() const;
signals:
    void refresh();

};


#endif //HARAMBE_THREAD_H
