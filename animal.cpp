#include "animal.h"

QString Animal::getAnimal() const
{
    return animal;
}

void Animal::setAnimal(const QString &value)
{
    animal = value;
}

QString Animal::getNome() const
{
    return nome;
}

void Animal::setNome(const QString &value)
{
    nome = value;
}

QString Animal::getIdade() const
{
    return idade;
}

void Animal::setIdade(const QString &value)
{
    idade = value;
}

QString Animal::getVacinado() const
{
    return vacinado;
}

void Animal::setVacinado(const QString &value)
{
    vacinado = value;
}

QString Animal::getCastrado() const
{
    return castrado;
}

void Animal::setCastrado(const QString &value)
{
    castrado = value;
}

QString Animal::getSituacao() const
{
    return situacao;
}

void Animal::setSituacao(const QString &value)
{
    situacao = value;
}

Animal::Animal()
{

}
