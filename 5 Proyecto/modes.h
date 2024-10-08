#ifndef MODES_H
#define MODES_H

/**
 * @file modes.h
 * @brief Define los modos de configuración para un grafo (dirigido o no dirigido).
 */

/**
 * @enum MODE
 * @brief Enumeración que representa el modo de configuración de un grafo.
 * 
 * Esta enumeración tiene dos posibles valores:
 * - `mode_DIRIGIDO`: El grafo es dirigido. Los arcos tienen una dirección y no son bidireccionales.
 * - `mode_NO_DIRIGIDO`: El grafo no es dirigido. Los arcos son bidireccionales.
 */
enum MODE
{
    mode_DIRIGIDO,     ///< Modo dirigido: los arcos tienen dirección.
    mode_NO_DIRIGIDO   ///< Modo no dirigido: los arcos son bidireccionales.
};

#endif // MODES_H
