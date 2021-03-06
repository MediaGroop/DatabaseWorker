// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PHYSICS_DATA_ODB_HXX
#define PHYSICS_DATA_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20300UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "PhysicsData.h"

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
  // PhysicsData
  //
  template <>
  struct class_traits< ::PhysicsData >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::PhysicsData >
  {
    public:
    typedef ::PhysicsData object_type;
    typedef ::PhysicsData* pointer_type;
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
  // PhysicsData
  //
  template <typename A>
  struct query_columns< ::PhysicsData, id_pgsql, A >
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

    // shape_id
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        int,
        pgsql::id_integer >::query_type,
      pgsql::id_integer >
    shape_id_type_;

    static const shape_id_type_ shape_id;

    // height
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        float,
        pgsql::id_real >::query_type,
      pgsql::id_real >
    height_type_;

    static const height_type_ height;

    // radius
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        float,
        pgsql::id_real >::query_type,
      pgsql::id_real >
    radius_type_;

    static const radius_type_ radius;

    // mass
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        float,
        pgsql::id_real >::query_type,
      pgsql::id_real >
    mass_type_;

    static const mass_type_ mass;

    // has_mass
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        bool,
        pgsql::id_boolean >::query_type,
      pgsql::id_boolean >
    has_mass_type_;

    static const has_mass_type_ has_mass;
  };

  template <typename A>
  const typename query_columns< ::PhysicsData, id_pgsql, A >::id_type_
  query_columns< ::PhysicsData, id_pgsql, A >::
  id (A::table_name, "\"id\"", 0);

  template <typename A>
  const typename query_columns< ::PhysicsData, id_pgsql, A >::shape_id_type_
  query_columns< ::PhysicsData, id_pgsql, A >::
  shape_id (A::table_name, "\"shape_id\"", 0);

  template <typename A>
  const typename query_columns< ::PhysicsData, id_pgsql, A >::height_type_
  query_columns< ::PhysicsData, id_pgsql, A >::
  height (A::table_name, "\"height\"", 0);

  template <typename A>
  const typename query_columns< ::PhysicsData, id_pgsql, A >::radius_type_
  query_columns< ::PhysicsData, id_pgsql, A >::
  radius (A::table_name, "\"radius\"", 0);

  template <typename A>
  const typename query_columns< ::PhysicsData, id_pgsql, A >::mass_type_
  query_columns< ::PhysicsData, id_pgsql, A >::
  mass (A::table_name, "\"mass\"", 0);

  template <typename A>
  const typename query_columns< ::PhysicsData, id_pgsql, A >::has_mass_type_
  query_columns< ::PhysicsData, id_pgsql, A >::
  has_mass (A::table_name, "\"has_mass\"", 0);

  template <typename A>
  struct pointer_query_columns< ::PhysicsData, id_pgsql, A >:
    query_columns< ::PhysicsData, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::PhysicsData, id_pgsql >:
    public access::object_traits< ::PhysicsData >
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

      // _shape_id
      //
      int _shape_id_value;
      bool _shape_id_null;

      // _height
      //
      float _height_value;
      bool _height_null;

      // _radius
      //
      float _radius_value;
      bool _radius_null;

      // _mass
      //
      float _mass_value;
      bool _mass_null;

      // _has_mass
      //
      bool _has_mass_value;
      bool _has_mass_null;

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

    static const std::size_t column_count = 6UL;
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
  class access::object_traits_impl< ::PhysicsData, id_common >:
    public access::object_traits_impl< ::PhysicsData, id_pgsql >
  {
  };

  // PhysicsData
  //
}

#include "PhysicsData-odb.ixx"

#include <odb/post.hxx>

#endif // PHYSICS_DATA_ODB_HXX
