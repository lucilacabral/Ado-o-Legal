#include "arquivo.h"

#include <QFile>

Arquivo::Arquivo()
{

}

bool Arquivo::salvarArquivo(QString fileName, QVector<Animal> animais)
{
    if(!animais.isEmpty())
    {
        QFile file(fileName);
        QString linha;
        if(!file.open(QIODevice::WriteOnly))
            return false;

        for(Animal a : animais)
        {
            linha = a.getAnimal() + ", " + a.getNome() + ", " + a.getIdade() + ", " + a.getVacinado() + ", " + a.getCastrado() + "\r\n";
            file.write(linha.toLocal8Bit());
        }
        return true;
    }
    return false;
}

QVector<Animal> Arquivo::carregarArquivoNoVetor(QString fileName)
{
    animais.clear();
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
        return animais;

    QString linha;
    Animal a;
    while(!file.atEnd())
    {
        linha = file.readLine();
        QStringList dados = linha.split(", ");
        a.setAnimal(dados[0]);
        a.setNome(dados[1]);
        a.setIdade(dados[2]);
        a.setVacinado(dados[3]);
        a.setCastrado(dados[4]);
        a.setSituacao(dados[5]);
        animais.push_back(a);
    }
    file.close();
    return animais;
}
