import java.util.Random;
import java.util.Scanner;

/**
 * Вынес отдельные части программы в функции, что позволило убрать дублирование кода.
 *
 * Например, кусок для того, чтобы продолжить или прекратить игру был
 * одинаковый в двух местах (начале программы и конце игры, когда ты угадал число).
 *
 * Можно было бы ещё подробить функцию Game() и вынести из неё кусок для проверки
 * близости числа к заданному, но я не уверен, что в этом есть смысл, так как этот кусок больше нигде не используется.
 *
 */
public class Guessing {

    public static boolean ContinueGame() {
        Scanner sc = new Scanner(System.in);
        String answer = sc.nextLine();
        if (answer.equals("нет")) {
            System.out.println("(×﹏×)");
            return false;
        } else if (!answer.equals("да")) {
            System.out.println("Непонятно, давай до свидания (︶︹︺)\n");
            return false;
        }
        System.out.println("Тогда играем! (⌒‿⌒)");
        return true;
    }

    public static void Game()
    {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int rand = new Random().nextInt(0, 10) + 1;
            System.out.println("Угадай число от 1 до 10");
            while (true) {
                int number = sc.nextInt();
                if (number == rand) {
                    System.out.println("Угадал! ╰(▔∀▔)╯");
                    System.out.println("Играем дальше? (да/нет)");
                    if (!ContinueGame()) {
                        return;
                    }
                    break;
                } else {
                    if (number < 1 || number > 10) {
                        System.out.println("Читать не умеешь? От 1 до 10!");
                    } else if (Math.abs(number - rand) > 5) {
                        System.out.println("Холодно");
                    } else if (Math.abs(number - rand) > 2) {
                        System.out.println("Тепло");
                    } else {
                        System.out.println("Жжётся!");
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("Привет!\nБудешь играть? (да/нет)");
        if (!ContinueGame()){
            return;
        }
        Game();

    }
}
