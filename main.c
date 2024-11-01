#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef enum segno { negativo, positivo } Segno;
typedef char* string;
typedef enum grado_eq { impossibile = -2, indeterminata = -1, primoGrado = 1, secondoGrado = 2 } GradoEq;

// elimina i decimali nulli se trascurabili (X.00)
void eliminaZeri(double valore, string seguito) {
  if(valore == 0) {
    printf("0%s", seguito);
  } else {
    if (valore - (int) valore == 0) {
      printf("%.0lf%s", valore, seguito);
    } else {
      printf("%.2lf%s", valore, seguito);
    }
  }
}

// stampa l'equazione di 2° grado in modo più leggibile, evitando di stampare i coefficienti nulli, unitari o negativi, ne valori decimali nulli
void stampaEqSanificata(double a, double b, double c, GradoEq grado) {
  printf("\nL'equazione ");
  
  // se il coefficiente a è nullo viene omesso
  if (a != 0) {
    // i coefficienti unitari vengono omessi
    if(a == 1) {
      printf("x² ");
    } else if (a == -1) {
      printf("-x² ");
    } else {
      eliminaZeri(a, "x² ");
    }
  }
  
  // sanificazione analoga al coefficiente a
  if(b != 0) {
    if (b == 1) {
      (a == 0) ? printf("x ") : printf("+ x ");
    } else if (b == -1) {
      printf("- x ");
    } else {
      if (b > 0) {
        if (a != 0) printf("+ ");
      } else {
        printf("- ");
        b = -b;
      }
      eliminaZeri(b, "x ");
    }
  }
  
  // sanificazione analoga al coefficiente a
  if(c != 0) {
    if (c > 0) {
      if (a != 0 || b != 0) printf("+ ");
    } else {
      printf("- ");
      c = -c;
    }
    eliminaZeri(c, " = 0 ");
  } else {
    printf("= 0 ");
  }

  switch(grado) {
    case primoGrado:
      printf("è di 1° grado e ");
    break;

    case secondoGrado: 
      printf("è di 2° grado e ");
    break;
    
    default:
      break;
  }
}

// calcola il delta dell'equazione di 2° grado
double getDelta(double a, double b, double c) {
  return (b * b) - (4 * a * c);
}

// calcola le radici dell'equazione di 2° grado utilizzando il delta
double getRadiceEq2(double a, double b, double delta, Segno segno) {
  return (-b + (segno ? sqrt(delta) : -sqrt(delta))) / (2 * a);
}

// restituisce il grado dell'equazione di 2° grado
int getGradoEq(double a, double b, double c) {
  // se a = 0 e b = 0 l'equazione è indeterminata (infinito soluzioni)
  // se a = 0 e b != 0 l'equazione è di 1° grado (una soluzione)
  // se a != 0 l'equazione è di 2° grado (due soluzioni)
  if (a == 0 && b == 0) {
    return (c == 0) ? indeterminata : impossibile;
  }
  return (a == 0) ? primoGrado : secondoGrado;
}

void stampaSoluzioni(double a, double b, double c) { 
  double delta;
  int grado = getGradoEq(a, b, c);
  
  stampaEqSanificata(a, b, c, grado);
  
  switch(grado) {
    case impossibile:
      printf("è impossibile e non ammette soluzioni reali.\n");
      break;
    
    case indeterminata:
      printf("è indeterminata e ammette infinite soluzioni.\n");
    break;
      
    case primoGrado:
      printf("ha una soluzione: x = ");
      eliminaZeri(-c / b, "\n");
    break;
      
    case secondoGrado:
      delta = getDelta(a, b, c);
    if (delta > 0) {
      double x1 = getRadiceEq2(a, b, delta, negativo);
      double x2 = getRadiceEq2(a, b, delta, positivo);
      printf("ha due soluzioni distinte: x₁ = ");
      eliminaZeri(x1, ", x₂ = ");
      eliminaZeri(x2, "\n");  
    } else if (delta == 0) {
      double x = getRadiceEq2(a, b, delta, positivo);
      printf("ha due soluzioni coincidenti: x₁ = x₂ = ");
      eliminaZeri(x, "\n");  
    } else {
      printf("non ammette soluzioni reali.\n");
    }
    break;
  }
}

int main() {
  printf("UniPG - Tutoraggio: esercizio equazioni di 2° grado. Made by https://www.github.com/matbagnoletti\n\n");
  
  // coefficienti dell'equazione di 2° grado
  double a, b, c;
  
  printf("Studio delle radici di una generica equazione di 2° grado del tipo: ax² + bx + c = 0\n\n");
  
  for(int i = 1; i < 4; i++) {
    switch (i) {
      case 1:
        printf("Inserisci il valore del coefficiente 'a': ");
        scanf("%lf", &a);
        break;
      case 2:
        printf("Inserisci il valore del coefficiente 'b': ");
        scanf("%lf", &b);
        break;
      case 3:
        printf("Inserisci il valore del coefficiente 'c': ");
        scanf("%lf", &c);
        break;
    }
  }

  printf("\nAttenzione! I risultati decimali verranno approssimati a sole 2 cifre.\n");
  
  stampaSoluzioni(a, b, c);
  
  return 0;
}