#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "arquivo.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Arquivo arquivo;
    QVector<Animal> lista_animais;

public:
    bool carregarVetorNaTabela(QVector<Animal> cliente);
    bool carregarTabelaNoVetor();
    bool adicionarAnimalNaTablea(Animal a, int line);
    bool limparTabelinha();
    bool atualizarTabela();

    void ordenarPorNome();
    void ordenarPorAnimal();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_confirm_clicked();

    void on_actionCarregar_Animais_triggered();

    void on_actionSalvar_Animais_triggered();

    void on_btn_cancel_clicked();

    void on_cbox_castrado_currentTextChanged(const QString &arg1);

    void on_tbl_Animal_cellDoubleClicked(int row, int column);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

bool compararAnimal(Animal a, Animal b);
bool compararNome(Animal a, Animal b);

#endif // MAINWINDOW_H
