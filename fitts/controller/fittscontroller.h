#ifndef FITTSCONTROLLER_H
#define FITTSCONTROLLER_H

#include <QApplication>
#include <QBarCategoryAxis>
#include <QBarSeries>
#include <QBarSet>
#include <QCategoryAxis>
#include <QChart>
#include <QChartView>
#include <QDebug>
#include <QElapsedTimer>
#include <QTimer>
#include <QDateTime>
#include <QHorizontalBarSeries>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLegend>
#include <QLineSeries>
#include <QObject>
#include <QPieSeries>
#include <QPieSlice>
#include <QStringList>
#include <QtGlobal>
#include <algorithm>

#include "keystrokemodel.h"

class FittsView;
class FittsModel;

class FittsController : public QObject {
	Q_OBJECT
public:
	FittsController();
	virtual ~FittsController();

	QList<FittsModel> *histModel;
    QJsonArray getHisto();


private:
    /**
     * @brief Afficher les résultats lorsque le test est terminé
     */
    void displayResults();

    /**
     * @brief Initialiser le test de la loi de Fitts
     */
	void initGame();

    /**
     * @brief Terminer le test de la loi de Fitts
     */
	void finish();

    /**
     * @brief Enregistrer les stats de la cible précédente et afficher la suivante
     */
	void nextCible();

    /**
     * @brief Calculer les résultats des graphes
     */
    void calculateResultHome();

    /**
     * @brief Ajouter un résultat au JSON
     */
	void addHisto();

	FittsModel *fittsModel;
	FittsView *fittsView;
	KeystrokeModel *keystrokeModel;

    QElapsedTimer *timer;
    bool keystrokeEvalStarted = false;

public slots:
    void showHelp();
    void initResultsScreen();
    void updateAValue(int);
    void updateBValue(int);

private slots:
    void initEvalScreen();
    void initSettingsScreen();

    void openJsonFile();

    void aValueChanged(double value);
	void bValueChanged(double value);
	void nbCibleChanged(int value);
	void minSizeChanged(int value);
	void maxSizeChanged(int value);

	void cibleClicked(int x, int y);
	
	/**
	 * @brief Sauvegarder les paramètres Keystroke dans le modèle
	 */
	void saveKeystrokeSettings();
	
	/**
	 * @brief Charger les paramètre Keystroke depuis le modèle et ouvrir la vue
	 */
	void loadKeystrokeSettings();
	
	/**
	 * @brief Démarrer le test du modèle Keystroke
	 */
	void startKeystrokeEval();

	/**
	 * @brief Terminer le test du modèle Keystroke
	 */
    void endKeystrokeEval(const QModelIndex &index);

    /**
     * @brief Démarrer le test du modèle Keystroke pour l'opérateur K
     */
    void startKeystrokeEval1();

    /**
     * @brief Suivi du test de du modèle de Keystroke pour l'opérateur K
     */
    void followUpKeystrokeEval1();

    /**
     * @brief Terminer le test du modèle Keystroke pour l'opérateur K
     */
    void endKeystrokeEval1();

};

#endif // FITTSCONTROLLER_H
