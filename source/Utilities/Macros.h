// © 2017 Joseph Cameron - All Rights Reserved
// Project: GDK
// Created on 2017-06-25.
#ifndef GDK_UTILITIES_MACROS_H
#define GDK_UTILITIES_MACROS_H

/* Creates a "static" class */
#define GDK_UNINSTANTIABLE(TypeName) \
TypeName() = delete; \
~TypeName() = delete; \
TypeName(const TypeName&) = delete; \
void operator =(const TypeName&) = delete;

/* deletes the copy constructor and assignment operator */
#define GDK_NO_COPY_OR_ASSIGN(TypeName) \
TypeName(const TypeName&) = delete;   \
void operator=(const TypeName&) = delete;

#endif /* GDK_UTILITIES_MACROS_H */
