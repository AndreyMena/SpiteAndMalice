#ifndef MAINVIEWCARDGAMES_H
#define MAINVIEWCARDGAMES_H

#include <QWidget>

#include "menujuego.h"

namespace Ui {
class MainViewCardGames;
}

class MainViewCardGames : public QWidget
{
    Q_OBJECT

public:
    explicit MainViewCardGames(QWidget *parent = nullptr);
    ~MainViewCardGames();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainViewCardGames *ui;
    int const CANTIDAD_JUEGOS = 11;
    std::string nombresJuegos[11] = {"Spite&Malice", "21", "OceansEleven",
                                 "Porrazo", "Panjpar", "Jhyap", "James Bond",
                                "Gin Rummy", "Escoba", "Durak", "Memory"};
    int indiceJuegoSeleccionado = 0;


private:
    /**
     * @brief addGameItems Agrega items a la lista de los juegos que se muestran
     * en la pantalla principal.
     */
    void agregaItemsJuego();

    /**
     * @brief cargaJuegoSeleccionado Se encarga de cargar el juego seleccionado
     * por el usuario
     */
    void cargaJuegoSeleccionado(int indiceJuego);
};

#endif // MAINVIEWCARDGAMES_H
