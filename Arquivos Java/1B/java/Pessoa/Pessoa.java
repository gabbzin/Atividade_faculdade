public class Pessoa { 
    private String nome; // Restrito à classe 
    protected int idade; // Acessível dentro do pacote ou por subclasses 
    public String endereco; // Livre acesso 

    public String getNome() { 
        return nome; 
    } 

    public void setNome(String nome) { 
        this.nome = nome; 
    } 
}