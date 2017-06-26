//
//  Macros.h
//  GDK
//
//  Created by Joseph Cameron on 2017-06-25.
//

#ifndef GDK_UTILITIES_MACROS_H
#define GDK_UTILITIES_MACROS_H

#define GDK_UNINSTANTIABLE(TypeName) \
TypeName() = delete; \
~TypeName() = delete; \
TypeName(const TypeName&) = delete; \
void operator =(const TypeName&) = delete;

#define GDK_DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&);   \
void operator=(const TypeName&)

#endif /* GDK_UTILITIES_MACROS_H */
