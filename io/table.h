/**
 * @file jtable.h
 * @author Joseph Leskey
 */

#ifndef J_TABLE_H
#define J_TABLE_H

/** Representation of table properties */
typedef struct JTableProperties {
    /** Number of columns */
    int columns;
    /** Widths of each column */
    int *widths;
} JTableProperties;

/**
 * Creates and initializes a table.
 *
 * @param[in] columns The number of columns
 * @param[in] ... The column widths
 */
JTableProperties jTableInit(int columns, ...);

/**
 * Cleans up a table no longer in use.
 *
 * @param[in] properties The table properties
 */
void jTableDestruct(JTableProperties *properties);

/**
 * Adjust a table to accomodate more data.
 *
 * @param[in] properties The table properties
 * @param[in] ... New columns
 */
void jTableAdjust(JTableProperties *properties, ...);

/**
 * Prints a table border.
 *
 * @param[in] properties The table properties
 */
void jTableBorder(JTableProperties *properties);

/**
 * Prints a table column.
 *
 * @param[in] width The width of the column
 * @param[in] content The content
 */
void jTableColumn(const int width, const char *content);

/**
 * Prints a table row.
 *
 * @param[in] properties The table properties
 * @param[in] ... Parameters
 */
void jTableRow(JTableProperties *properties, ...);

#endif // J_TABLE_H
