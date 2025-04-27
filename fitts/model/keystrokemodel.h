#ifndef KEYSTROKEMODEL_H
#define KEYSTROKEMODEL_H

#include <QString>
#include <QList>

class KeystrokeModel {
public:
	KeystrokeModel();
	
    // Dernier temps expérimental relevé
	int lastMeasuredTime;

    // Tableau des temps mesurés
    QList<qint64> mesuredTimes;

    // Durées du modèle Keystroke, valeurs par défaut paramètrables depuis l'interface
	int k = 200;
	int p = 1100;
	int h = 400;
	int m = 1300;
};

#endif // KEYSTROKEMODEL_H
