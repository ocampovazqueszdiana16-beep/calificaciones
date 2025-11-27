#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct RegistroEstudiante {
    std::string nombre;
    int materias;
    std::vector<double> promediosMaterias;
    double promedioFinal;
};

int main() {

    std::vector<RegistroEstudiante> historial;

    int repetir = 1;

    while (repetir == 1) {

        int materias;
        const int PARCIALES = 3;
        std::string nombre;

        std::cout << "=============================================\n";
        std::cout << "     CALCULO DE PROMEDIO DE ESTUDIANTE\n";
        std::cout << "=============================================\n";

        std::cin.ignore();
        std::cout << "Ingrese el nombre del estudiante: ";
        std::getline(std::cin, nombre);

        std::cout << "Ingrese el numero de materias: ";
        std::cin >> materias;

        if (materias <= 0) {
            std::cout << "Numero invalido. El programa terminara.\n";
            break;
        }

        double sumaMateria, promedioMateria, promedioFinal = 0.0;
        double nota;

        RegistroEstudiante reg;
        reg.nombre = nombre;
        reg.materias = materias;

        for (int m = 1; m <= materias; m++) {
            std::cout << "\nMateria " << m << ": ingrese las " << PARCIALES
                      << " calificaciones:\n";

            sumaMateria = 0.0;

            for (int p = 1; p <= PARCIALES; p++) {
                std::cout << "  Parcial " << p << ": ";
                std::cin >> nota;

                while (nota < 0 || nota > 10) {
                    std::cout << "  Valor invalido. Ingrese un numero entre 0 y 10: ";
                    std::cin >> nota;
                }

                sumaMateria += nota;
            }

            promedioMateria = sumaMateria / PARCIALES;
            promedioFinal += promedioMateria;

            reg.promediosMaterias.push_back(promedioMateria);

            std::cout << "  Promedio de Materia " << m << ": "
                      << std::fixed << std::setprecision(2)
                      << promedioMateria << "\n";
        }

        promedioFinal = promedioFinal / materias;
        reg.promedioFinal = promedioFinal;

        std::cout << "\n=============================================\n";
        std::cout << "PROMEDIO FINAL DEL ESTUDIANTE: "
                  << std::fixed << std::setprecision(2) << promedioFinal << "\n";

        if (promedioFinal >= 6.0)
            std::cout << "ESTADO: APROBADO\n";
        else
            std::cout << "ESTADO: REPROBADO\n";

        std::cout << "=============================================\n\n";

        // Guardar registro
        historial.push_back(reg);

        // Opción para repetir
        std::cout << "¿Desea ingresar otro estudiante?\n";
        std::cout << "1 = SI\n";
        std::cout << "2 = NO (Mostrar reporte final)\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> repetir;

        if (repetir != 1) {
            std::cout << "\nFinalizando e imprimiendo reporte...\n\n";
            break;
        }
    }

    // ============================
    // REPORTE FINAL DE ESTUDIANTES
    // ============================

    std::cout << "=============================================\n";
    std::cout << "     REPORTE FINAL DE TODOS LOS ESTUDIANTES\n";
    std::cout << "=============================================\n\n";

    for (size_t i = 0; i < historial.size(); i++) {
        std::cout << "Estudiante #" << i + 1 << ": " << historial[i].nombre << "\n";
        std::cout << "Materias registradas: " << historial[i].materias << "\n";

        for (int m = 0; m < historial[i].materias; m++) {
            std::cout << "  Promedio Materia " << m + 1 << ": "
                      << std::fixed << std::setprecision(2)
                      << historial[i].promediosMaterias[m] << "\n";
        }

        std::cout << "  Promedio Final: "
                  << std::fixed << std::setprecision(2)
                  << historial[i].promedioFinal << "\n";

        if (historial[i].promedioFinal >= 6.0)
            std::cout << "  Estado: APROBADO\n\n";
        else
            std::cout << "  Estado: REPROBADO\n\n";
    }

    std::cout << "=============================================\n";
    std::cout << "        FIN DEL REPORTE\n";
    std::cout << "=============================================\n";

    return 0;
}

