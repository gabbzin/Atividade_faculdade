public class CarroTeste {
    public static void main(String[] args){
        Carro carro1 = new Carro();
        carro1.marca = "Toyota";
        carro1.modelo = "Corolla";
        carro1.ano = 2020;
        carro1.acelerar();
        
        System.out.println("Marca: " + carro1.marca);
        System.out.println("Modelo: " + carro1.modelo);
        System.out.println("Ano: " + carro1.ano);
    }
}