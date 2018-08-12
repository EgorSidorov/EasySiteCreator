#include "ddos_defender.h"
#include <QMutableHashIterator>
#include <QTime>
#include <QString>

ddos_defender* ddos_defender::getInstance()
{
    static ddos_defender obj_ddos_defender;
    return &obj_ddos_defender;
}

bool ddos_defender::ip_check(QHostAddress user_address)
{
    obj_mutex.lock();
    QMutableHashIterator<QHostAddress,QStringList> iter_hash_ip_address(hash_ip_address);
    iter_hash_ip_address.toFront();
    while(iter_hash_ip_address.hasNext())
    {
        iter_hash_ip_address.next();
        if(user_address.isEqual(iter_hash_ip_address.key()))
        {
            QTime time = QTime::fromString(iter_hash_ip_address.value().at(1));
            int count_visit = iter_hash_ip_address.value().at(0).toInt();
            //блокировка
            if(time.msecsTo(QTime::currentTime()) < 1000 && count_visit > 5 )
            {
                QStringList user_stringlist;
                user_stringlist.append(QString::number(++count_visit));
                user_stringlist.append(QTime::currentTime().toString());
                iter_hash_ip_address.setValue(user_stringlist);
                obj_mutex.unlock();
                return false;
            }
            //новое посещение менее, чем за 1 секунды, но не очень много запросов
            else if( time.msecsTo(QTime::currentTime()) < 1000 )
            {
                iter_hash_ip_address.value().removeAt(0);
                iter_hash_ip_address.value().prepend(QString::number(++count_visit));
                obj_mutex.unlock();
                return true;
            }
            //посещение больше 1 секунды назад
            else
            {
                QStringList user_stringlist;
                user_stringlist.append(QString::number(1));
                user_stringlist.append(QTime::currentTime().toString());
                iter_hash_ip_address.setValue(user_stringlist);
                obj_mutex.unlock();
                return true;
            }
        }
    }
    QStringList user_info;
    user_info.append(QString::number(1));
    user_info.append(QTime::currentTime().toString());
    hash_ip_address.insert(user_address,user_info);
    obj_mutex.unlock();
    return true;
}

ddos_defender::ddos_defender()
{

}

