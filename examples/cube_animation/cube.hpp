#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "abcgOpenGL.hpp"
#include "vertex.hpp"

class Cube {
public:
  void loadObj(std::string_view path);
  void paint();
  void update(float deltaTime);
  void create(GLuint program, GLint modelMatrixLoc, GLint colorLoc,
              GLint normalMatrixLoc, glm::mat4 viewMatrix, float scale, int N);
  void destroy() const;
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();

private:
  GLuint m_VAO{};
  GLuint m_VBO{};
  GLuint m_EBO{};

  glm::mat4 m_animationMatrix{1.0f};
  glm::mat4 m_viewMatrix;
  glm::mat4 m_positionMatrix{1.0f};
  glm::mat4 m_modelMatrix{1.0f};
  GLint m_modelMatrixLoc;
  GLint m_colorLoc;

  std::vector<Vertex> m_vertices;
  std::vector<GLuint> m_indices;
  enum class Orientation { DOWN, RIGHT, UP, LEFT }; // 0,1,2,3
  enum class PlaneFace {
    C_UPPER,
    C_FRONT,
    C_BOTTOM,
    C_REAR,
    C_RIGHT,
    C_LEFT
  }; // 0,1,2,3,4,5

  // Position and animation properties
  glm::vec3 m_position{};
  float m_angle;
  float m_maxPos;
  float m_scale{1.0f};
  bool m_border{false};
  bool m_isMoving{false};
  float m_angleVelocity{360.0f};
  Orientation m_orientation{Orientation::DOWN};
  PlaneFace m_planeface{PlaneFace::C_UPPER};

  // Light properties
  GLint m_KaLoc;
  GLint m_KdLoc;
  GLint m_KsLoc;
  GLint m_normalMatrixLoc;
  bool m_hasNormals{false};
  float m_Ka{0.7};
  float m_Kd{0.3};
  float m_Ks{0.1};

  void createBuffers();
  void computeNormals();
  void move(float deltaTime);
  void translate();
  void resetAnimation();
};

#endif