public class Main {

    public static void main(String[] args) {
        Carro meuCarro = new Carro("uno", "prata",2.0);

        System.out.println("Carro criado, digite uma velocidade:");
        meuCarro.setVelocidade(220);
        meuCarro.acelerar(0);
        System.out.printf("velocidade = " + meuCarro.getVelocidade());
    }
}
