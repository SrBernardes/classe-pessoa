#include <iostream>

using namespace std;

int achando_idade (string DataNascimento, string DataHoje);

int achando_idade (string DataNascimento, string DataHoje, int *meses, int *dias)
{

    int diaN=0, mesN=0, anoN=0, diaH=0, mesH=0, anoH=0;

    for (int i=0, j=10; i<2; i++, j/=10)
    {
        diaN += (DataNascimento[i]-'0') * j;
        diaH += (DataHoje[i]-'0') * j;
    }
    if (diaN>31 || diaN<=0 ||diaH>31 || diaH<=0)
    {
        return -1;
    }

    for (int i=3, j=10; i<5; i++, j/=10)
    {
        mesN += (DataNascimento[i]-'0') * j;
        mesH += (DataHoje[i]-'0') * j;
    }
    if (mesN>12 || mesN<=0 || mesH>12 || mesH<=0)
    {
        return -1;
    }
    if ((mesN==2 && diaN>29) || (mesH==2 && diaH>29))
    {
        return -1;
    }

    for (int i=6, j=1000; i<10; i++, j/=10)
    {
        anoN += (DataNascimento[i]-'0') * j;
        anoH += (DataHoje[i]-'0') * j;
    }
    if (anoN>anoH)
    {
        return -1;
    }

    else if (anoN==anoH)
    {
        if (mesN>mesH || (mesN==mesH && diaN>diaH))
        {
            return -1;
        }

    }
    if (anoN<1900 || anoN>2020 || anoH<1900 || anoH>2020)
    {
        return -1;
    }
    double TudoEmAnosNascimento = anoN + ((double)mesN/12.0) + ((double)diaN/365.25);
    double TudoEmAnosHoje = anoH + ((double)mesH/12.0) + ((double)diaH/365.25);
    int IDADE = TudoEmAnosHoje - TudoEmAnosNascimento;
    *meses = mesH - mesN + 6;
    *dias = diaH - diaN;

    return IDADE;
}

class Pessoa
{
public:
    string nome;
    int idade;
    float altura;

    double correr(double tempo);
    double pular();
};

double Pessoa:: correr(double tempo)
{
    return (1000 * altura - 2 * idade) * tempo;
}

double Pessoa:: pular()
{
    return 300 * altura - 3 * idade;
}

int main()
{
    Pessoa A, B, C, D;
    string Nascimento, Hoje;
    int Age = -1, meses = 0, dias = 0;

    printf("Digite a data de hoje(valida) no formato DD/MM/AAAA: ");
    getline(cin, Hoje);

    A.nome = "Gilson";
    while (Age==-1)
    {
        printf("\n- Digite a data de nascimento(valida) do %s no formato DD/MM/AAAA: ", A.nome.c_str());
        getline(cin, Nascimento);
        Age = achando_idade(Nascimento, Hoje, &meses, &dias);
    }
    cout << "meses = " << meses << endl << "dias = " << dias << endl;
    cout << endl;
    A.idade = Age;
    Age = -1, meses = 0, dias = 0;
    A.altura = 1.75;

    B.nome = "Samara";
    while (Age==-1)
    {
        printf("- Digite a data de nascimento(valida) da %s no formato DD/MM/AAAA: ", B.nome.c_str());
        getline(cin, Nascimento);
        Age = achando_idade(Nascimento, Hoje, &meses, &dias);
    }
    cout << endl;
    B.idade = Age;
    Age = -1, meses = 0, dias = 0;
    B.altura = 1.60;

    C.nome = "Samuel";
    while (Age==-1)
    {
        printf("- Digite a data de nascimento(valida) do %s no formato DD/MM/AAAA: ", C.nome.c_str());
        getline(cin, Nascimento);
        Age = achando_idade(Nascimento, Hoje, &meses, &dias);
    }
    cout << endl;
    C.idade = Age;
    Age = -1, meses = 0, dias = 0;
    C.altura = 1.75;

    D.nome = "ALessandra";
    while (Age==-1)
    {
        printf("- Digite a data de nascimento(valida) da %s no formato DD/MM/AAAA: ", D.nome.c_str());
        getline(cin, Nascimento);
        Age = achando_idade(Nascimento, Hoje, &meses, &dias);
    }
    D.idade = Age;
    D.altura = 1.63;

    double Corrida, Pulo;

    Corrida = A.correr(10);
    Pulo = A.pular();
    printf("\nNome: %s | Idade: %d anos, %d meses e %d dias | Altura: %.2f | Espaco Percorrido em 10s: %.2f cm | Altura do Pulo: %.2f cm\n", A.nome.c_str(), A.idade, meses, dias, A.altura, Corrida, Pulo);

    Corrida = B.correr(10);
    Pulo = B.pular();
    printf("\nNome: %s | Idade: %d anos, %d meses e %d dias | Altura: %.2f | Espaco Percorrido em 10s: %.2f cm | Altura do Pulo: %.2f cm\n", B.nome.c_str(), B.idade, meses, dias, B.altura, Corrida, Pulo);

    Corrida = C.correr(10);
    Pulo = C.pular();
    printf("\nNome: %s | Idade: %d anos, %d meses e %d dias | Altura: %.2f | Espaco Percorrido em 10s: %.2f cm | Altura do Pulo: %.2f cm\n", C.nome.c_str(), C.idade, meses, dias, C.altura, Corrida, Pulo);

    Corrida = D.correr(10);
    Pulo = D.pular();
    printf("\nNome: %s | Idade: %d anos, %d meses e %d dias | Altura: %.2f | Espaco Percorrido em 10s: %.2f cm | Altura do Pulo: %.2f cm\n", D.nome.c_str(), D.idade, meses, dias, D.altura, Corrida, Pulo);

    return 0;
}
