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
    /**
     * @brief MainViewCardGames Muestra la pantalla donde se seleccionara el juego deseado
     * @param parent Parámetro de la clase padre QWidget
     */
    explicit MainViewCardGames(QWidget *parent = nullptr);

    /**
     * Destructor de la clase
     */
    ~MainViewCardGames();

private slots:
    /**
     * @brief on_pushButton_clicked Boton para confirmar el juego deseado y comenzar a jugar.
     */
    void on_pushButton_clicked();

    /**
     * @brief on_comboBox_activated Boton con menu de lista desplegable
     * @param index El item de la lista que se selecciona
     */
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
