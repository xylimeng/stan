#include <stan/model/sized_var_decl.hpp>
#include <test/unit/util.hpp>

TEST(sized_var_decl, one) {
  using stan::model::sized_var_decl;
  std::vector<int> sizes;
  sizes.push_back(3);
  sizes.push_back(4);
  sized_var_decl d("foo", "bar", 3, false, true, sizes);

  // test values
  EXPECT_EQ("foo", d.name());
  EXPECT_EQ("bar", d.type_name());
  EXPECT_EQ(3, d.array_dims());
  EXPECT_FALSE(d.has_lower_bound());
  EXPECT_TRUE(d.has_upper_bound());
  stan::test::expect_eq(sizes, d.sizes());
  for (size_t i = 0; i < sizes.size(); ++i) {
    EXPECT_EQ(sizes[i], d.sizes()[i]);
  }

  // test constant references
  EXPECT_EQ(&d.name(), &d.name());
  EXPECT_EQ(&d.type_name(), &d.type_name());
  EXPECT_EQ(&d.sizes(), &d.sizes());

}