package zoologico;

import java.util.ArrayList;

import zoologico.Animal;

public class Main {
	public static void main(String[] args) {
		ArrayList<Animal> animais = new ArrayList<Animal>();
		
		Animal elefante = new Animal("Robet", 10, Animal.Tipo.ELEFANTE, Animal.Comer.COMEU, animais);
		Animal leao = new Animal("Simba", 5, Animal.Tipo.LEAO, Animal.Comer.COMEU);
        
		animais.add(leao);
		animais.add(elefante);
		
		elefante.matarAnimal("Robet", 10, Animal.Tipo.ELEFANTE, Animal.Comer.COMEU);
		animais.remove(elefante);
		
		/*imprimindo todos os animais*/
		for(Animal animal : animais) {
			System.out.println(animal.getNome() + " é um " + animal.getTipo() + " e " + animal.getComer());
		}
	}
}
