package exercicio06;

import java.text.SimpleDateFormat;
import java.time.DateTimeException;
import java.time.LocalDate;
import java.util.Date;

public class Data {
    private int dia;
    private int mes;
    private int ano;

    // metodo que verifica se a data é uma data valida
    // Metodo para imprimir a data 01/04/1900
    // Metodo proximoDia()  que deve atualizar a data para o proximo dia
    // Construtor sem parametos, que quando invocado deve criar um objeto do tipo data, com a data do Sistema operacional


    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public Data() {
        // como o localDate.agora ele pega a data atual
        LocalDate hoje = LocalDate.now();

        // pega um dia do mes
        this.dia = hoje.getDayOfMonth();
        this.mes = hoje.getMonthValue();
        this.ano = hoje.getYear();
    }


    // Verifica se a data é válida
    public boolean validaData() {
        if (getAno() < 1 || getMes() < 1 || getMes() > 12 || getDia() < 1) {
            return false;
        }
        try {
            LocalDate.of(ano, mes, dia);
        } catch (DateTimeException e) {
            return false;
        }
        return true;
    }


    // Método para avançar a data para o próximo dia
    public void proximoDia() {
        LocalDate dataAtual = LocalDate.of(this.ano, this.mes, this.dia);
        LocalDate proximaData = dataAtual.plusDays(1);
        this.dia = proximaData.getDayOfMonth();
        this.mes = proximaData.getMonthValue();
        this.ano = proximaData.getYear();
    }

    public void imprimirData(){
        // podeiria usar uma mascara do SimpleDateFormat
        // dessa forma é mais facil

        System.out.println(getDia()+"/"+getMes()+"/"+getAno());
    }


    public int getDia() {
        return dia;
    }

    public void setDia(int dia) {
        this.dia = dia;
    }

    public int getMes() {
        return mes;
    }

    public void setMes(int mes) {
        this.mes = mes;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }
}
