#ifndef DDOS_DEFENDER_H
#define DDOS_DEFENDER_H


#include <QTcpSocket>
#include <QMutex>
#include <QHostAddress>
#include <QStringList>
#include <QHash>

class ddos_defender
{
public:
    static ddos_defender *getInstance();
    bool ip_check(QHostAddress user_address);
private:
    ddos_defender();

    QHash< QHostAddress,QStringList > hash_ip_address;
    QMutex obj_mutex;
};


#endif // DDOS_DEFENDER_H
