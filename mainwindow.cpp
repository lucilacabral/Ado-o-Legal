#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::carregarVetorNaTabela(QVector<Animal> animais)
{
    for (Animal a : animais)
    {
        int line = ui->tbl_Animal->rowCount();
        ui->tbl_Animal->insertRow(line);
        adicionarAnimalNaTablea(a, line); // adiciona animal a tabela
    }
    return false;
}

bool MainWindow::carregarTabelaNoVetor()
{
    Animal animal;
    int tamanhoTable = ui->tbl_Animal->rowCount();
    for (int i = 0; i < tamanhoTable; i++)
    {
        //QString nome = ui->tbl_Animal;
        //animal.setNome(nome);
    }
    return false;
}

bool MainWindow::adicionarAnimalNaTablea(Animal a, int line)
{
    ui->tbl_Animal->setItem(line, 0, new QTableWidgetItem(a.getAnimal()));
    ui->tbl_Animal->setItem(line, 1, new QTableWidgetItem(a.getNome()));
    ui->tbl_Animal->setItem(line, 2, new QTableWidgetItem(a.getIdade()));
    ui->tbl_Animal->setItem(line, 3, new QTableWidgetItem(a.getVacinado()));
    ui->tbl_Animal->setItem(line, 4, new QTableWidgetItem(a.getCastrado()));
    ui->tbl_Animal->setItem(line, 5, new QTableWidgetItem(a.getSituacao()));

    ui->line_nome->setText("");
    ui->line_idade->setText("");
    ui->line_animal->setText("");
    ui->cbox_vacinado->setCurrentText("-");
    ui->cbox_castrado->setCurrentText("-");
    ui->lbl_situacao->setText("");

    return false;
}

bool MainWindow::limparTabelinha()
{
    if(ui->tbl_Animal->rowCount() != 0)
    {
        for(int i = ui->tbl_Animal->rowCount(); i >= 0; i--)
        {
            ui->tbl_Animal->removeRow(i);
        }
        return true;
    }
    return false;
}

bool MainWindow::atualizarTabela()
{
    limparTabelinha();
    carregarVetorNaTabela(lista_animais);
    return true;
}

void MainWindow::ordenarPorNome()
{
    std::sort(lista_animais.begin(), lista_animais.end(), compararNome);
}

void MainWindow::ordenarPorAnimal()
{
    std::sort(lista_animais.begin(), lista_animais.end(), compararAnimal);
}


void MainWindow::on_btn_confirm_clicked()
{
    if((ui->line_nome->text() != "") && (ui->line_idade->text() != "") && (ui->line_animal->text() != "")
            && (ui->cbox_castrado->currentText() != "-"))
    {
        Animal animal;
        animal.setAnimal(ui->line_animal->text());
        animal.setNome(ui->line_nome->text());
        animal.setIdade(ui->line_idade->text());
        animal.setVacinado(ui->cbox_vacinado->currentText());
        animal.setCastrado(ui->cbox_castrado->currentText());
        animal.setSituacao(ui->lbl_situacao->text());

        int linha = ui->tbl_Animal->rowCount();
        ui->tbl_Animal->insertRow(linha);
        adicionarAnimalNaTablea(animal, linha);

        lista_animais.push_back(animal);
    }
}


void MainWindow::on_actionCarregar_Animais_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                 "s",
                                                 " ",
                                                 "TXT(*.txt)");
    if(file != "")
    {
        if(!lista_animais.isEmpty())
        {
            limparTabelinha();

            lista_animais = arquivo.carregarArquivoNoVetor(file);
            carregarVetorNaTabela(lista_animais);
        }
        else
        {
            lista_animais = arquivo.carregarArquivoNoVetor(file);
            carregarVetorNaTabela(lista_animais);
        }
    }
}

void MainWindow::on_actionSalvar_Animais_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                        "s",
                                        " ",
                                        "TXT(*.txt)");

    if(!arquivo.salvarArquivo(file, lista_animais))
    {
        QMessageBox::warning(this, "NOT SAVE", "ERRO! Tabela Vazia", QMessageBox::Ok);
    }
}

void MainWindow::on_btn_cancel_clicked()
{
    ui->line_nome->setText("");
    ui->line_idade->setText("");
    ui->line_animal->setText("");
    ui->cbox_vacinado->setCurrentText("-");
    ui->cbox_castrado->setCurrentText("-");
    ui->lbl_situacao->setText("");
}

void MainWindow::on_cbox_castrado_currentTextChanged(const QString &arg1)
{
    if(arg1 == "SIM")
    {
        ui->lbl_situacao->setText("Adotavel");
    }
    else if(arg1 == "NAO")
    {
        ui->lbl_situacao->setText("Nao Adotavel");
    }
}

void MainWindow::on_tbl_Animal_cellDoubleClicked(int row, int column)
{
    if(column == 0)
    {
       QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar o animal selecionado?");
       if(resp == QMessageBox::Yes)
       {
           bool ok;
           QString txt = QInputDialog::getText(this, "Alterar Animal", "Novo Animal", QLineEdit::Normal, "", &ok);
           if(ok and !txt.isEmpty())
           {
               lista_animais[row].setAnimal(txt);
           }
           atualizarTabela();
       }
       else if(resp == QMessageBox::No)
       {
            atualizarTabela();
       }
    }
    else if(column == 1)
    {
        QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar o nome do animal?");
        if(resp == QMessageBox::Yes)
        {
            bool ok;
            QString txt = QInputDialog::getText(this, "Alterar nome do animal", "Novo nome", QLineEdit::Normal, "", &ok);
            if(ok and !txt.isEmpty())
            {
                lista_animais[row].setNome(txt);
            }
            atualizarTabela();
        }
        else if(resp == QMessageBox::No)
        {
             atualizarTabela();
        }
    }
    else if(column == 2)
    {
        QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar editar a idade do animal?");
        if(resp == QMessageBox::Yes)
        {
            bool ok;
            QString txt = QInputDialog::getText(this, "Alterar idade do animal", "Nova idade", QLineEdit::Normal, "", &ok);
            if(ok and !txt.isEmpty())
            {
                lista_animais[row].setIdade(txt);
            }
            atualizarTabela();
        }
        else if(resp == QMessageBox::No)
        {
             atualizarTabela();
        }
    }
    else if(column == 3)
    {
        QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Itens", "Você desejar alterar se o animal foi vacinado?");
        if(resp == QMessageBox::Yes)
        {
            bool ok;
            QString txt = QInputDialog::getText(this, "Alterar Situação", "Nova Situação", QLineEdit::Normal, "", &ok);
            if(ok and !txt.isEmpty())
            {
                lista_animais[row].setVacinado(txt);
            }
            atualizarTabela();
        }
        else if(resp == QMessageBox::No)
        {
             atualizarTabela();
        }
    }
    else if(column == 4 || column == 5)
    {
        QMessageBox::warning(this, "Error!", "COLUNA IMUTÁVEL", QMessageBox::Ok);
        atualizarTabela();
    }
}

bool compararNome(Animal a, Animal b)
{
    return a.getNome() < b.getNome();
}

bool compararAnimal(Animal a, Animal b)
{
    return a.getAnimal() < b.getAnimal();
}

void MainWindow::on_pushButton_3_clicked()
{
    ordenarPorNome();
    atualizarTabela();
}

void MainWindow::on_pushButton_2_clicked()
{
    ordenarPorAnimal();
    atualizarTabela();
}

void MainWindow::on_pushButton_clicked()
{
    int castrados = 0;
    int vacinados = 0;
    for(Animal a : lista_animais)
    {
        if(a.getCastrado() == "SIM")
        {
            castrados++;
        }
        if(a.getVacinado() == "SIM")
        {
            vacinados++;
        }
    }
    ui->lbl_pronto_pra_adocao->setText(QString::number(castrados));
    ui->lbl_vacinado->setText(QString::number(vacinados));
}







