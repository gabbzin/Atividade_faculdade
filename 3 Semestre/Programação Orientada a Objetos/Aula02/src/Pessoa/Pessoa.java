public class Pessoa {
    String nome;
    int idade;
    double altura;

    public void seApresentar(){
        System.out.println("Meu nome é " + this.nome + ", tenho " + this.idade + " anos de idade.");
    }

    public void dizerSuaAltura(){
        System.out.println("Minha altura é: " + this.altura);
    }
}
