package org.example;

public class Main {
    public static void main(String[] args) {
        Grafo mapa = new Grafo();

        mapa.adicionarCidade("Gama");
        mapa.adicionarCidade("Novo Gama");
        mapa.adicionarCidade("ValParaíso");
        mapa.adicionarCidade("Ceilândia");
        mapa.adicionarCidade("Osfaya");

        mapa.conectarCidade("Gama", "Novo Gama");
        mapa.conectarCidade("Gama", "Ceilandia");
        mapa.conectarCidade("Osfaya", "ValParaíso");

        mapa.mostrarGrafo();
    }
}