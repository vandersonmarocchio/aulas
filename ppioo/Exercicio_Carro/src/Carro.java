public class Carro {
    private String modelo;
    private String cor;
    private double motor;
    private double velocidade;

    public Carro(String modelo, String cor, double motor) {
        this.modelo = modelo;
        this.cor = cor;
        this.motor = motor;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public double getMotor() {
        return motor;
    }

    public void setMotor(double motor) {
        if (motor < 1) this.motor = 1.0;
        else this.motor = motor;
    }

    public double getVelocidade() {
        return velocidade;
    }

    public void setVelocidade(double velocidade) {
        this.velocidade = velocidade;
    }

    public void acelerar(double velocidade) {
        if (velocidade > this.motor * 110.00) {
            System.out.printf("Erro, velocidade maior que a potencia do carro!");
        } else if (velocidade < 0) {
                System.out.printf("Erro, numero incorreto!");
          } else this.velocidade += velocidade;
    }

    public void frear(double velocidade){
        if (velocidade>=60){
            System.out.println("Airbag disparado!! O carro parou");
            this.velocidade = 0;
        } else if (velocidade < 0){
            System.out.printf("Erro, numero incorreto!");
            } else this.velocidade -= velocidade;
        if (this.velocidade <0){
            this.velocidade = 0;
        }
    }

    public void verEstado(double velocidade){
        if (velocidade == 0){
            System.out.println("Parado!");
        } else if (velocidade > 0){
            System.out.printf("Em movimento a" + velocidade + "km/h.");
        }
    }

 }