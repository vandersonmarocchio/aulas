import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Carro meuCarro = new Carro("UNO", "Prata",1.4);
        Scanner scanner = new Scanner(System.in);
        System.out.println("Carro criado, digite uma velocidade:");
        meuCarro.setVelocidade(scanner.nextDouble());
        meuCarro.verEstado();
        System.out.println("Agora digite uma velocidade para acelerar:");
        meuCarro.acelerar(scanner.nextDouble());
        meuCarro.verEstado();
        System.out.println("Agora digite uma velocidade para frear:");
        meuCarro.frear(scanner.nextDouble());
        meuCarro.status();
    }
}
