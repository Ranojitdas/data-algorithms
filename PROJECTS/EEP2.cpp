//Exercício extra 2 - Prova POO
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
    int cargo;

public:
    //metodos

    //contrutor
    funcionario(long c, float s, int i, int d, int ca):cpf(c), salario(s), idade(i), departamento(d), cargo(ca){
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

    int getCargo(){return cargo;}
    void setCargo(int ca){cargo = ca;}

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
    empresa(long cn, long c, float s, int i, int d):cnpj(cn), funcionario(c, s, i, d, ca){
        cout << "empresa " << cnpj << " criada" << endl;
        funcionarios = new funcionario*[qtdFunc];
    }
    //destrutor
    ~empresa(){
        cout << "empresa " << cnpj << " removida" << endl;
        for(int i = 0; i < qtdFunc; i++){
            delete funcionarios[i];
        }
        delete[] funcionarios;
    }

    long getCnpj(){return cnpj;}
    void setCnpj(long cn){cnpj = cn;}

    int getQtdFunc(){return qtdFunc;}
    void setQtdFunc(int ca){qtdFunc = ca;}

    void addfuNC(funcionario* f){
        for(int i = 0; i < qtdFunc; i++){
            if(funcionarios[i] == NULL){
                funcionarios[i] = f;
                return;
            }
        cout << "Empresa cheia com " << qtdFunc << "funcionarios" << endl;
        }
    }

    void print(){
        printf("__________________________________\n");
        cout << "Funcionarios da Empresa " << cnpj << endl;
        for(int i = 0; i < qtdFunc; i++){
            if(funcionarios[i] != NULL){
                funcionarios[i]->printInfo();
            }
        }
    }

    //metodo para aumento de salario

    void setAumento(int departamento, float percentual){
        for(int i = 0; i < qtdFunc; i++){
            if(funcionarios[i] != NULL && funcionarios[i]->getDepartamento() == departamento){
                funcionarios[i]->setSalario(funcionarios[i]->getSalario() * (1 + percentual));
            }
        }
    
    void setAumentoGerente(int cargo){
        for(int i = 0; i < qtdFunc; i++){
            if(funcionarios[i] != NULL && funcionarios[i]->getCargo() == cargo){
                funcionarios[i]->setSalario(funcionarios[i]->getSalario() * (1 + 0.15));
            }
        }
    }
    
    void addCargo(int cargo){
        for (int i = 0; i < qtdFunc; i++){
            if(funcionarios[i] != NULL){
                funcionarios[i]->setCargo(cargo);
            }
        }
        
    }
};

///Gerente, Analista e Técnico

class gerente: public funcionario{
    int cargo;

public:
    gerente(long c, float s, int i, int d, int ca, int car): cargo(car), funcionario(c, s, i, d, ca),{ 
        cout << "gerente " << cargo << " criado" << endl;
    }
    ~gerente(){
        cout << "gerente " << cargo << " removido" << endl;
    }

};  


class analista: public funcionario{
    int cargo;

public:
    analista(long c, float s, int i, int d, int ca, int car): cargo(car), funcionario(c, s, i, d, ca),{ 
        cout << "analista " << cargo << " criado" << endl;
    }
    ~analista(){
        cout << "analista " << cargo << " removido" << endl;
    }
};

class tecnico: public funcionario{
    int cargo;
    
public: 
    tecnico(long c, float s, int i, int d, int ca, int car): cargo(car), funcionario(c, s, i, d, ca),{ 
        cout << "tecnico " << cargo << " criado" << endl;
    }
    ~tecnico(){
        cout << "tecnico " << cargo << " removido" << endl;
    }
};

int main(void){

    long cpf, cnpj;
    float salario;
    int idade, dep, num_func, cargo;

    funcionario* func;
    empresa* emp;

    printf("__________________________________\n");
    cout << "Exercicio Extra 2" << endl;
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
        cout << "Digite o cargo do funcionario "<< i << ": "; 
        cin >> cargo;
        func = new funcionario(cpf, idade, salario, dep, cargo);
    }

    printf("__________________________________\n");

    //empresa
    cout << "Digite o cnpj da empresa: ";
	cin >> cnpj;
    emp = new empresa(cnpj, cpf, idade, salario, dep);

    //aumento por departamento
    cout << "Digite o numero do departamento que deseja dar um aumento: ";
	cin >> dep;
    emp->setAumento(dep);
    cout << "Departamento " << dep << " recebeu aumento de 10%" << endl;

    //mostrando o info
    for(int i = 0; i < num_func; i++){emp[i].printInfo();}    

    //chamando metodo destrutor
    delete emp;
    delete func;
}

///printinfo com lixo de memoria
///emp chama criação do ultimo func