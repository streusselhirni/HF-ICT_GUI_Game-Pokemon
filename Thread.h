//
// Created by Nicolas Haenni on 2019-05-18.
//

#ifndef HARAMBE_THREAD_H
#define HARAMBE_THREAD_H


#include <QThread>

class Thread : public QThread
{
    Q_OBJECT;
public:
    Thread();
private:
    void run() override;
signals:
    void refresh();
};


#endif //HARAMBE_THREAD_H
