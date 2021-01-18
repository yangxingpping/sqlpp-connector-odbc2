// generated by .\ddl2cpp .\sample.sql ./demo/demo hhhhh sqlpp11
#ifndef HHHHH_DEMO_H
#define HHHHH_DEMO_H

#include <sqlpp11/table.h>
#include <sqlpp11/data_types.h>
#include <sqlpp11/char_sequence.h>

namespace hhhhh
{
  namespace TabBar_
  {
    struct Alpha
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "alpha";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T alpha;
            T& operator()() { return alpha; }
            const T& operator()() const { return alpha; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::bigint, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update, sqlpp::tag::can_be_null>;
    };
    struct Beta
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "beta";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T beta;
            T& operator()() { return beta; }
            const T& operator()() const { return beta; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::varchar, sqlpp::tag::can_be_null>;
    };
    struct Gamma
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "gamma";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T gamma;
            T& operator()() { return gamma; }
            const T& operator()() const { return gamma; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::boolean, sqlpp::tag::require_insert>;
    };
    struct Delta
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "delta";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T delta;
            T& operator()() { return delta; }
            const T& operator()() const { return delta; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::can_be_null>;
    };
  } // namespace TabBar_

  struct TabBar: sqlpp::table_t<TabBar,
               TabBar_::Alpha,
               TabBar_::Beta,
               TabBar_::Gamma,
               TabBar_::Delta>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "tab_bar";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T tabBar;
        T& operator()() { return tabBar; }
        const T& operator()() const { return tabBar; }
      };
    };
  };
} // namespace hhhhh
#endif