#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "animal.h"
#include <QVector>

class Arquivo
{
private:
    QVector<Animal> animais;

public:
    Arquivo();
    bool salvarArquivo(QString fileName, QVector<Animal> animais);
    QVector<Animal> carregarArquivoNoVetor(QString fileName);
};

#endif // ARQUIVO_H
