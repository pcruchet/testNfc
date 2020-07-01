#include "lecteurnfc.h"
#include <QNearFieldManager>
#include <QNearFieldTarget>
#include <QByteArray>
#include <QDebug>

LecteurNFC::LecteurNFC(QObject *parent) : QObject(parent)
{

    manager = new QNearFieldManager(this);
    if (!manager->isAvailable()) {
        qWarning() << "NFC non disponible";
        return;
    }


    while(!manager->startTargetDetection());
    connect(manager, &QNearFieldManager::targetDetected,
            this, &LecteurNFC::targetDetected);
    connect(manager, &QNearFieldManager::targetLost,
            this, &LecteurNFC::targetLost);
}

LecteurNFC::~LecteurNFC()
{
    manager->stopTargetDetection();
}

void LecteurNFC::targetDetected(QNearFieldTarget *target)
{
    if (!target)
        return;

    QByteArray uid = target->uid();
    emit tagDetecte(uid.toHex(' ').toUpper());
}

void LecteurNFC::targetLost(QNearFieldTarget *target)
{
    if (target)
        target->deleteLater();
}
