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


/**
 * @enum TYPE
 * @brief Enumeración que representa el typo de grafo.
 * 
 * Esta enumeración tiene dos posibles valores:
 * - `type_FLOW`: El grafo se implementa pensando en flujo.
 * - `type_PETRI`: El grafo se implementa pensando en los grafos de Petri.
 */
enum TYPE
{
    type_NONE,          ///< Modo por defecto: No tiene ninguna caracteristica especial.
    type_FLOW,          ///< Modo Flujo: Este modo utiliza el objeto `flow_capacity`
    type_PETRI          ///< Modo Petri: Se utiliza para trabajar con redes de Petri.

};


#endif // MODES_H
