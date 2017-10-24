import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Carro meuCarro = new Carro("UNO", "Prata",true,1.4);
        Scanner scanner = new Scanner(System.in);
        int x = 1;
        System.out.println("Carro ligado, digite uma velocidade para começar: (Km/h)");
        meuCarro.setVelocidade(scanner.nextDouble());
        meuCarro.detalhes();
        while (x!=0) {
            System.out.println("\n\nMenu:");
            System.out.println("1 - Ligar");
            System.out.println("2 - Desligar");
            System.out.println("3 - Acelerar");
            System.out.println("4 - Frear");
            System.out.println("5 - Detalhes do carro");
            System.out.println("0 - Sair");
            x = scanner.nextInt();
            switch (x) {
                case 1:
                    meuCarro.ligar();
                    meuCarro.verEstado();
                    break;
                case 2:
                    meuCarro.desligar();
                    meuCarro.verEstado();
                    break;
                case 3:
                    System.out.println("Digite uma velocidade para acelerar: (Km/h)");
                    meuCarro.acelerar(scanner.nextDouble());
                    meuCarro.verEstado();
                    break;
                case 4:
                    System.out.println("Digite uma velocidade para frear: (Km/h)");
                    meuCarro.frear(scanner.nextDouble());
                    meuCarro.verEstado();
                    break;
                case 5:
                    meuCarro.detalhes();
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Número inválido!!");
                    break;
            }
        }
        scanner.close();
    }
}
