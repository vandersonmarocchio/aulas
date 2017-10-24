public class Carro {
    private String modelo;
    private String cor;
    private double motor;
    private boolean ignicao;
    private double velocidade;
    private double max_velocidade;

    public Carro(String modelo, String cor, boolean ignicao, double motor) {
        this.modelo = modelo;
        this.cor = cor;
        this.motor = motor;
        this.ignicao = ignicao;
        this.max_velocidade = this.motor *110;
    }

    public Carro(){
        this(null, null,false ,0);
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
        if (velocidade > this.motor * 110.00){
            System.out.println("Velocidade maior que a potencia do carro");
        } else this.velocidade = velocidade;
    }

    public double getMax_velocidade() {
        return max_velocidade;
    }

    public void setMax_velocidade(double max_velocidade) {
        this.max_velocidade = max_velocidade;
    }

    public boolean isIgnicao(){
        return ignicao;
    }

    public void setIgnicao(boolean ignicao) {
        this.ignicao = ignicao;
    }

    public void acelerar(double velocidade) {
        if (isIgnicao() == false) System.out.println("Ligue o carro primeiro!");
            else if ((this.velocidade + velocidade) > (getMax_velocidade())) {
                System.out.println("Erro!! Velocidade maior que a potencia do carro!");
                System.out.println("O carro só pode atingir até " + getMax_velocidade() + ".");
                this.velocidade = getMax_velocidade();
            }   else if (velocidade < 0) {
                    System.out.println("Erro, número inválido!");
                }   else this.velocidade += velocidade;
    }

    public void frear(double velocidade){
        if (isIgnicao() == false) System.out.println("Ligue o carro primeiro!");
            if (velocidade>=60){
                System.out.println("Airbag disparado!!");
                this.velocidade = 0;
            }   else if (velocidade < 0) System.out.println("Erro, número inválido!");
                    else if (this.velocidade <= 0) System.out.println("O carro está parado, impossível frear mais!!");
                        else if (this.velocidade < velocidade) {
                            System.out.println("Velocidade de frenagem maior que a velocidade atual");
                            this.velocidade = 0;
                        }   else this.velocidade -= velocidade;
    }

    public void verEstado(){
        if (this.velocidade == 0 && this.ignicao == true){
            System.out.println("Carro parado e ligado.");
        }   else if (this.velocidade == 0 && this.ignicao == false)
                System.out.println("Carro desligado.");
                else if (this.velocidade > 0){
                    System.out.println("Em movimento a " + this.velocidade + "km/h.");
        }
    }

    public void detalhes(){
        System.out.println("\nModelo: " + getModelo());
        System.out.println("Cor: " + getCor());
        System.out.println("Motor: " + getMotor());
        if (isIgnicao()==true) System.out.println("Estado: Ligado");
        else System.out.println("Estado: Desligado");
        System.out.println("Velocidade Máxima: " + getMax_velocidade());
        verEstado();
    }

    public void ligar(){
        if (getVelocidade()>0 || this.ignicao == true ) System.out.println("O carro já está ligado!");
        else this.ignicao = true;
    }

    public void desligar(){
        if (getVelocidade()>0) System.out.println("O carro está em movimento, pare o carro para desligar!!");
        else if (this.ignicao == false) System.out.println("O carro já está desligado!");
        else this.ignicao = false;
    }
}