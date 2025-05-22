package org.atividade;

import java.util.*;

public class Grafo {
    // Mapa onde a chave é a cidade e o valor é a lista de cidades conectadas
    Map<String, List<String>> conexoes = new HashMap<>();

    // Adicionando a cidade (vértice)
    public void adicionarCidade(String nome){
        conexoes.putIfAbsent(nome, new ArrayList<>());
    }

    public void conectarCidade(String cidade1, String cidade2){
        // Inicializa listas se as cidades ainda não estiverem no mapa
        conexoes.putIfAbsent(cidade1, new ArrayList<>());
        conexoes.putIfAbsent(cidade2, new ArrayList<>());

        // Adiciona a conexão bidirecional
        conexoes.get(cidade1).add(cidade2);
        conexoes.get(cidade2).add(cidade1);
    }


    // Mostrar tudo (grafo)
    public void mostrarGrafo(){
        for (String cidade: conexoes.keySet()){
            System.out.println(cidade + " conecta com: " + conexoes.get(cidade));
        }
    }
}
