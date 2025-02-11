# 📌 Gestión de Productos

## 📖 Descripción
Este proyecto en C++ tiene como objetivo gestionar productos ingresados por el usuario, permitiendo capturar su información, determinar cuál es el más costoso y calcular el total de los precios ingresados. 

El programa interactúa con el usuario a través de la consola, donde solicita el nombre y el precio de cada producto, los compara para encontrar el más caro y, finalmente, muestra los resultados de manera clara y estructurada.

## 🎯 Objetivo
El propósito de este programa es practicar y reforzar conocimientos sobre:
- Manejo de clases y objetos en C++.
- Entrada y salida de datos mediante `cin` y `cout`.
- Uso de estructuras de control como ciclos y condicionales.
- Implementación de funciones para modularizar el código y mejorar su legibilidad.

## 🚀 Funcionamiento
El programa sigue la siguiente lógica:
1. Se solicita al usuario que ingrese el nombre y precio de un producto.
2. Se almacena la información y se compara el precio del producto actual con el más alto registrado hasta el momento.
3. Se acumula el precio de cada producto ingresado para calcular el total.
4. El usuario puede decidir si desea ingresar otro producto o finalizar la captura.
5. Al terminar, se muestra el producto más caro junto con el total de los precios ingresados.

## 🛠️ Estructura del Código
El código está organizado de la siguiente manera:

- **Clase `Producto`**
  - Contiene los atributos `nombre` y `precio`.
  - Implementa métodos `set` y `get` para acceder y modificar estos atributos.

- **Función `ingresarProducto`**
  - Solicita al usuario que ingrese el nombre y precio de un producto.
  - Usa los métodos `set` de la clase `Producto` para almacenar la información.

- **Función `determinarProductoMasCaro`**
  - Compara cada producto ingresado con el producto más caro registrado.
  - Actualiza la información si se encuentra un producto con mayor precio.

- **Función `mostrarResultados`**
  - Muestra en pantalla el producto más caro ingresado y su precio.
  - Imprime el total acumulado de los precios de todos los productos.

- **Función `main`**
  - Coordina la ejecución del programa.
  - Controla el flujo de ingreso de datos mediante un bucle `do-while`.
  - Llama a las funciones correspondientes para capturar datos, procesarlos y mostrar resultados.

## 📌 Requisitos Previos
Para compilar y ejecutar este programa, necesitas:
- Un compilador de C++.
- Un editor de código o IDE como Visual Studio Code, Visual Studio Community o cualquier otro de tu preferencia.



## 👥 Autores
Este proyecto fue desarrollado por:
- **Juventino Eduardo Martínez Hernández**
- **Angelica Yazmin Mendoza**
- **Alejandro Almanza López**
- **Karla Mártinez Aboytes**

