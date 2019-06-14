#ifndef ANIMAL_H
#define ANIMAL_H
#include <QString>

class Animal
{
private:
    QString animal;
    QString nome;
    QString idade;
    QString vacinado;
    QString castrado;
    QString situacao;

public:
    Animal();

    QString getAnimal() const;
    void setAnimal(const QString &value);

    QString getNome() const;
    void setNome(const QString &value);

    QString getIdade() const;
    void setIdade(const QString &value);

    QString getVacinado() const;
    void setVacinado(const QString &value);

    QString getCastrado() const;
    void setCastrado(const QString &value);

    QString getSituacao() const;
    void setSituacao(const QString &value);
};

#endif // ANIMAL_H
