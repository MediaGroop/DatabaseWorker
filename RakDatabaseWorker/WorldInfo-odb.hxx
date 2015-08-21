// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef WORLD_INFO_ODB_HXX
#define WORLD_INFO_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "WorldInfo.h"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // WorldInfo
  //
  template <>
  struct class_traits< ::WorldInfo >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::WorldInfo >
  {
    public:
    typedef ::WorldInfo object_type;
    typedef ::WorldInfo* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef int id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // WorldInfo
  //
  template <typename A>
  struct query_columns< ::WorldInfo, id_pgsql, A >
  {
    // id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    id_type_;

    static const id_type_ id;

    // name
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    name_type_;

    static const name_type_ name;

    // x
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        float,
        pgsql::id_real >::query_type,
      pgsql::id_real >
    x_type_;

    static const x_type_ x;

    // y
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        float,
        pgsql::id_real >::query_type,
      pgsql::id_real >
    y_type_;

    static const y_type_ y;

    // z
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        float,
        pgsql::id_real >::query_type,
      pgsql::id_real >
    z_type_;

    static const z_type_ z;
  };

  template <typename A>
  const typename query_columns< ::WorldInfo, id_pgsql, A >::id_type_
  query_columns< ::WorldInfo, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::WorldInfo, id_pgsql, A >::name_type_
  query_columns< ::WorldInfo, id_pgsql, A >::
  name (A::table_name, "\"name\"", 0);

  template <typename A>
  const typename query_columns< ::WorldInfo, id_pgsql, A >::x_type_
  query_columns< ::WorldInfo, id_pgsql, A >::
  x (A::table_name, "\"x\"", 0);

  template <typename A>
  const typename query_columns< ::WorldInfo, id_pgsql, A >::y_type_
  query_columns< ::WorldInfo, id_pgsql, A >::
  y (A::table_name, "\"y\"", 0);

  template <typename A>
  const typename query_columns< ::WorldInfo, id_pgsql, A >::z_type_
  query_columns< ::WorldInfo, id_pgsql, A >::
  z (A::table_name, "\"z\"", 0);

  template <typename A>
  struct pointer_query_columns< ::WorldInfo, id_pgsql, A >:
    query_columns< ::WorldInfo, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::WorldInfo, id_pgsql >:
    public access::object_traits< ::WorldInfo >
  {
    public:
    struct id_image_type
    {
      int id_value;
      bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // _id
      //
      int _id_value;
      bool _id_null;

      // _name
      //
      details::buffer _name_value;
      std::size_t _name_size;
      bool _name_null;

      // _x
      //
      float _x_value;
      bool _x_null;

      // _y
      //
      float _y_value;
      bool _y_null;

      // _z
      //
      float _z_value;
      bool _z_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 5UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, const object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::WorldInfo, id_common >:
    public access::object_traits_impl< ::WorldInfo, id_pgsql >
  {
  };

  // WorldInfo
  //
}

#include "WorldInfo-odb.ixx"

#include <odb/post.hxx>

#endif // WORLD_INFO_ODB_HXX
