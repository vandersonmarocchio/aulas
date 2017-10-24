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
        if ((this.velocidade + velocidade) > (this.motor * 110.00)) {
            System.out.println("Erro, velocidade maior que a potencia do carro!");
            System.out.println("O carro só pode atingir até " + (this.motor * 110.00));
        } else if (velocidade < 0) {
                System.out.println("Erro, numero incorreto!");
          } else this.velocidade += velocidade;
    }

    public void frear(double velocidade){
        if (velocidade>=60){
            System.out.println("Airbag disparado!!");
            this.velocidade = 0;
        } else if (velocidade < 0){
            System.out.printf("Erro, numero incorreto!");
            } else this.velocidade -= velocidade;
        if (this.velocidade <0){
            this.velocidade = 0;
        }
    }

    public void verEstado(){
        if (this.velocidade == 0){
            System.out.println("Status: Parado");
        } else if (this.velocidade > 0){
            System.out.println("Em movimento a " + this.velocidade + "km/h.");
        }
    }

    public void status(){
        System.out.println("Modelo: " + this.modelo);
        System.out.println("Cor: " + this.cor);
        System.out.println("Motor: " + this.motor);
        verEstado();
    }

 }