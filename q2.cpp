/*
Samila Ellen Garrido Rodrigues - 20210026788
*/
/*
2) Modifique o programa anterior para admitir novos tipos de funcionários, os 
quais serãodefinidos a partir de novas classes que herdarão da classe original 
que representa o funcionário. Serão definidas as subclasses para funcionários
do tipo Gerente, Analista e Técnico, os quais deverão sobrecarregar o métodos
para exibição dos dados do funcionário, de forma que exiba qual o cargo do 
funcionário consultado. O programa anterior deve ser alterado para:
    • Solicitar o cargo do funcionário adicionado;
    • Aumentar o salário dos gerentes em 15% ao término do cadastro destes
    • Exibir ao final do cadastro todos os funcionários e suas informações
     – utilizar funções virtuais.
*/

#include <iostream>
#include <stdio.h>



class Funcionario{
    long cpf;
    float salario;
    int idade;
    int departamento;
    int cargo;

public:
    Funcionario(long c, float s, int i, int d, int cg): cpf(c), salario(s), idade(i), departamento(d), cargo(cg)  { 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Funcionario %ld criado com sucesso!\n", cpf);
    
    }
    ~Funcionario(){ 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Funcionario %ld removido com sucesso!\n", cpf);
    }
    
    long get_cpf() { 
        return cpf;
    }
    void set_cpf(long c) { 
        cpf = c;
    }
    float get_salario() {
        return salario;
    }
    void set_salario(float s){
        salario = s;
    }
    int get_idade() {
        return idade;
    }
    void set_idade(int i){
        idade = i;
    }
    int get_departamento() {
        return departamento;
    }
    void set_departamento(int d){
        departamento = d;
    }
    int get_cargo() {
        return cargo;
    }
    void set_cargo(int cg){
        cargo = cg;
    }

    void print(){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Funcionario %ld\n", cpf);
        printf("Salario: %.2f \n", salario);
        printf("Idade: %d \n", idade);
        printf("Departamento: %d \n", departamento);
        printf("Cargo: %d \n", cargo);
    }
};

class Empresa{
    long cnpj;
    int qtd_funcionarios;
    Funcionario** funcionarios;

public:
    
    Empresa(long c, int q): cnpj(c), qtd_funcionarios(q) {
        printf("=-=-=-=-=-=-=-=\n");
        printf("Empresa %ld criada com sucesso!\n", cnpj);
        funcionarios = new Funcionario*[qtd_funcionarios];
    }
    ~Empresa(){ 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Empresa %ld removida com sucesso!\n", cnpj);
        for(int i = 0; i < qtd_funcionarios; i++){
            delete funcionarios[i];
        }
        delete[] funcionarios;
    }
    
    long get_cnpj() { 
        return cnpj;
    }
    void set_cnpj(long c) { 
        cnpj = c;
    }
    int get_qtd_funcionarios() {
        return qtd_funcionarios;
    }
    void set_qtd_funcionarios(int q){
        qtd_funcionarios = q;
    }
    
    void add_funcionario(Funcionario* f){
        for(int i = 0; i < qtd_funcionarios; i++){
            if(funcionarios[i] == NULL){
                funcionarios[i] = f;
                return;
            }
        }
        printf("=-=-=-=-=-=-=-=\n");
        printf("Empresa %ld sem espaço\n", cnpj);
    }


    void print(){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Empresa %ld\n", cnpj);
        for(int i = 0; i < qtd_funcionarios; i++){
            if(funcionarios[i] != NULL){
                funcionarios[i]->print();
            }
        }
    }
    void aumenta_salario(int departamento, float percentual){
        for(int i = 0; i < qtd_funcionarios; i++){
            if(funcionarios[i] != NULL && funcionarios[i]->get_departamento() == departamento){
                funcionarios[i]->set_salario(funcionarios[i]->get_salario() * (1 + percentual));
            }
        }
    
    }
    void aumenta_salario_gerente(int cargo){
        for(int i = 0; i < qtd_funcionarios; i++){
            if(funcionarios[i] != NULL && funcionarios[i]->get_cargo() == cargo){
                funcionarios[i]->set_salario(funcionarios[i]->get_salario() * (1 + 0.15));
            }
        }
    }
    void adiciona_cargo(int cargo){
        for (int i = 0; i < qtd_funcionarios; i++){
            if(funcionarios[i] != NULL){
                funcionarios[i]->set_cargo(cargo);
            }
        }
        
    }
};

class Gerente : public Funcionario{
    int cargo;
public:
    Gerente(long c, float s, int i, int d, int cg, int car): Funcionario(c, s, i, d, cg), cargo(car) { 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Gerente %ld criado com sucesso!\n", c);
    
    }
    ~Gerente(){ 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Gerente %ld removido com sucesso!\n", get_cpf());
    }
    void print(){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Gerente %ld\n", get_cpf());
        printf("Salario: %.2f \n", get_salario());
        printf("Idade: %d \n", get_idade());
        printf("Departamento: %d \n", get_departamento());
        printf("Cargo: %d \n", cargo);
    }
};

class Analista : public Funcionario{
    int cargo;
public:
    Analista(long c, float s, int i, int d, int cg,int car): Funcionario(c, s, i, d, cg), cargo(car) { 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Analista %ld criado com sucesso!\n", c);
    
    }
    ~Analista(){ 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Analista %ld removido com sucesso!\n", get_cpf());
    }
    void print(){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Analista %ld\n", get_cpf());
        printf("Salario: %.2f \n", get_salario());
        printf("Idade: %d \n", get_idade());
        printf("Departamento: %d \n", get_departamento());
        printf("Cargo: %d \n", cargo);
    }
};

class Tecnico : public Funcionario{
    int cargo;
public:
    Tecnico(long c, float s, int i, int d,int cg,  int car): Funcionario(c, s, i, d, cg), cargo(car) { 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Tecnico %ld criado com sucesso!\n", c);
    
    }
    ~Tecnico(){ 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Tecnico %ld removido com sucesso!\n", get_cpf());
    }
    void print(){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Tecnico %ld\n", get_cpf());
        printf("Salario: %.2f \n", get_salario());
        printf("Idade: %d \n", get_idade());
        printf("Departamento: %d \n", get_departamento());
        printf("Cargo: %d \n", cargo);
    }
};



int main(){
    long cnpj;
    int qtd_funcionarios;
    long cpf;
    float salario;
    int idade;
    int departamento;
    int departamento_aumento;
    float percentual_aumento;
    int cargo_aumento; // 1 - Gerente, 2 - Analista, 3 - Tecnico
    Empresa* empresa;


    printf("=-=-=-=-=-=-=-=\n");
    printf("Digite o CNPJ da empresa: ");
    scanf("%ld", &cnpj);
    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &qtd_funcionarios);
    empresa = new Empresa(cnpj, qtd_funcionarios);

    for(int i = 0; i < qtd_funcionarios; i++){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Digite o CPF do funcionario %d: ", i);
        scanf("%ld", &cpf);
        printf("Digite o salario do funcionario %d: ", i);
        scanf("%f", &salario);
        printf("Digite a idade do funcionario %d: ", i);
        scanf("%d", &idade);
        printf("Digite o departamento do funcionario %d: ", i);
        scanf("%d", &departamento);
        printf("Digite o cargo do funcionario %d (1- Gerente; 2- Analista, 3- Tecnico): ", i);
        scanf("%d", &cargo_aumento);
        empresa->add_funcionario(new Funcionario(cpf, salario, idade, departamento, cargo_aumento));
    }

    empresa->print();



    if (cargo_aumento == 1){
        new Gerente(cpf, salario, idade, departamento, cargo_aumento, cargo_aumento);
    }
    else if (cargo_aumento == 2){
        new Analista(cpf, salario, idade, departamento, cargo_aumento, cargo_aumento);
    }
    else if (cargo_aumento == 3){
        new Tecnico(cpf, salario, idade, departamento, cargo_aumento, cargo_aumento);
    }
    else{
        printf("=-=-=-=-=-=-=-=\n");
        printf("Cargo invalido!\n");
    }
    empresa->print();

    printf("=-=-=-=-=-=-=-=\n");

    if (cargo_aumento == 1){
        empresa->aumenta_salario_gerente(cargo_aumento);
    }
    empresa->print();


    delete empresa;

    return 0;

}
