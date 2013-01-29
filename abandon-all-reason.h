// Zero and its successors.

class Z {
public:
  operator unsigned() {
    return 0;
  }
};

template <class t>
class S {
public:
  operator unsigned() {
    return 1 + t();
  }
};

typedef S<Z> One;

// A template used for defining the resulting type.

template <class t>
class Val {
public:
  typedef t V;
};

// Logic. Z is false, all other types are true.

template <class a, class b>
class Nor :
  public Val<Z>
{};

template <>
class Nor <Z, Z> :
  public Val<One>
{};

template <class a>
class Not :
  public Val<typename Nor<a, a>::V>
{};

template <class a, class b>
class And :
  public Val<typename Nor<typename Nor<a, a>::V,
                          typename Nor<b, b>::V
                          >::V>
{};

template <class i, class t, class e>
class If :
  public Val<t>
{};

template <class t, class e>
class If <Z, t, e> :
  public Val<e>
{};

// Comparison.

template <class a, class b>
class Gt;

template <class a, class b>
class Gt <S<a>, S<b> > :
  public Val<typename Gt<a, b>::V>
{};

template <>
class Gt <Z, Z> :
  public Val<Z>
{};

template <class a>
class Gt <a, Z> :
  public Val<One>
{};

template <class b>
class Gt <Z, b> :
  public Val<Z>
{};

template <class a, class b>
class Eq :
  public Val<typename And<typename Not<typename Gt<a, b>::V>::V,
                          typename Not<typename Gt<b, a>::V>::V
                          >::V>
{};

// Arithmetic.

template <class a, class b>
class Add;

template <class a, class b>
class Add <S<a>, b> :
  public Val<typename Add<a, S<b> >::V>
{};

template <class b>
class Add <Z, b> :
  public Val<b>
{};

template <class a, class b>
class Sub;

template <class a, class b>
class Sub <S<a>, S<b> > :
  public Val<typename Sub<a, b>::V>
{};

template <>
class Sub <Z, Z> :
  public Val<Z>
{};

template <class b>
class Sub <Z, b> :
  public Val<Z>
{};

template <class a>
class Sub <a, Z> :
  public Val<a>
{};

template <class a>
class Pred :
  public Val<typename Sub<a, One>::V>
{};

template <class a, class b>
class Mul;

template <class a, class b>
class Mul <S<a>, b> :
  public Val<typename Add<b, typename Mul<a, b>::V>::V>
{};

template <class b>
class Mul <Z, b> :
  public Val<Z>
{};

template <class a, class b>
class Mod :
  public Val<typename If<typename Gt<b, a>::V,
                         a,
                         typename Mod<typename Sub<a, b>::V, b>::V>::V>
{};

template <class b>
class Mod <Z, b> :
  public Val<Z>
{};

template <class a, class b>
class Divides :
  public Val<typename Not<typename Mod<a, b>::V>::V>
{};

template <class a, class b>
class DivisorsUpTo :
  public Val<typename Add<typename Divides<a, b>::V,
                          typename DivisorsUpTo<a, typename Pred<b>::V>::V
                          >::V>
{};

template <class a>
class DivisorsUpTo <a, One> :
  public Val<One>
{};

template <class a>
class Divisors :
  public Val<S<typename DivisorsUpTo<a, typename Pred<a>::V>::V> >
{};

template <>
class Divisors <One> :
  public Val<One>
{};

// Primality test. Why not?

template <class a>
class Prime :
  public Val<typename Eq<typename Divisors<a>::V, S<One> >::V>
{};

// Transformation from unsigned to Peano numbers.

template <unsigned n>
class Peano :
  public Val<S<typename Peano<n - 1>::V> >
{};

template <>
class Peano <0> :
  public Val<Z>
{};
