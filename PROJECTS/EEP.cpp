//Exercício extra 1 - Prova POO
//Yhasmim Tigre

//biblioteca
#include <iostream>
#include <stdlib.h>

//usaremos esses comandos de forma implicita 
using std::cout;
using std::cin;
using std::endl;

//classes

class funcionario{

    //atributos
    long cpf;
    float salario; 
    int idade;
    int departamento;

public:
    //metodos

    //contrutor
    funcionario(long c, float s, int i, int d):cpf(c), salario(s), idade(i), departamento(d){
        cout << "funcionario " << cpf << " criado" << endl;
    }
    //destrutor
    ~funcionario(){
        cout << "funcionario " << cpf << " removido" << endl;
    }

    long getCpf(){return cpf;}
    void setCpf(long c){cpf = c;}

    float getSalario(){return salario;}
    void setSalario(float s){salario = s;}

    int getIdade(){return cpf;}
    void setIdade(int i){idade = i;}

    int getDepartamento(){return departamento;}
    void setDepartamento(int d){departamento = d;}

    void printInfo(){
        printf("__________________________________\n");
        cout << "informacoes do(s) funcionario(s)" << endl;
        printf("__________________________________\n");
        cout << "CPF: " << cpf << endl;
        cout << "salario: " << salario << endl;
        cout << "idade: " << idade << endl;
        cout << "departamento: " << departamento << endl;
    }
};

class empresa: public funcionario{ //empresa herda de funcionário
    
    //atributos
    long cnpj;
    int qtdFunc;
    funcionario** funcionarios; 
public:
    //metodos

    //contrutor
    empresa(long cn, long c, float s, int i, int d):cnpj(cn), funcionario(c, s, i, d){
        cout << "empresa " << cnpj << " criada" << endl;
    }
    //destrutor
    ~empresa(){
        cout << "empresa " << cnpj << " removida" << endl;
    }

    long getCnpj(){return cnpj;}
    void setCnpj(long cn){cnpj = cn;}

    int getQtdFunc(){return qtdFunc;}
    void setQtdFunc(int ca){qtdFunc = ca;}

    void addfunc(funcionario* f){
        for(int i = 0; i < qtdFunc; i++){
            if(funcionarios[i] == NULL){
                funcionarios[i] = f;
                return;
            }
        cout << "Empresa cheia com " << qtdFunc << "funcionarios" << endl;
        }
    }

    //metodo para aumento de salario
    void setaumento(int d){
        if (getDepartamento() == d){setSalario(getSalario() + 1.1*getSalario());}
    }
};

int main(void){

    long cpf, cnpj;
    float salario;
    int idade, dep, num_func;

    funcionario* func;
    empresa* emp;

    printf("__________________________________\n");
    cout << "Exercicio Extra 1" << endl;
    cout << "Yhasmim Tigre - 20210026966" << endl;
    printf("__________________________________\n");

    //funcionários
    cout << "Digite o numero de funcionarios que deseja adicionar: ";
	cin >> num_func;
    
    for (int i = 0; i < num_func; i++){
        cout << "Digite o cpf do funcionario " << i << ": ";
        cin >> cpf;
        cout << "Digite o salario do funcionario "<< i << ": ";
        cin >> salario;
        cout << "Digite a idade do funcionario "<< i << ": ";
        cin >> idade;
        cout << "Digite o numero do departamento do funcionario "<< i << ": "; 
        cin >> dep; 
        emp->addFunc(func = new funcionario(cpf, idade, salario, dep));
    }

    printf("__________________________________\n");

    //empresa
    cout << "Digite o cnpj da empresa: ";
	cin >> cnpj;
    emp = new empresa(cnpj, cpf, idade, salario, dep);

    //aumento por departamento
    cout << "Digite o numero do departamento que deseja dar um aumento: ";
	cin >> dep;
    emp->setaumento(dep);
    cout << "Departamento " << dep << " recebeu aumento de 10%" << endl;

    //mostrando o info
    for(int i = 0; i < num_func; i++){emp[i].printInfo();}    

    //chamando metodo destrutor
    delete emp;
    delete func;
}

///printinfo com lixo de memoria
///emp chama criação do ultimo func
