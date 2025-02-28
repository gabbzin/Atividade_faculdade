public class PessoaMain {
    public static void main(String[] args){
        Pessoa pessoa = new Pessoa();

        pessoa.nome = "Gabriel";
        pessoa.idade = 18;
        pessoa.altura = 1.84;

        pessoa.seApresentar();
        pessoa.dizerSuaAltura();
    }
}
