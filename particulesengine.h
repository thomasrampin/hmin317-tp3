#ifndef PARTICULESENGINE_H
#define PARTICULESENGINE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <vector>
#include <random>
#include "particle.h"

#define MAX_PARTICULES 10000

struct ParticleData {
    QVector4D posSize, color;
    ParticleData(QVector4D ps, QVector4D c)
        : posSize(ps)
        , color(c)
    {}
};

class ParticuleEngine : QOpenGLFunctions
{
public:
    ParticuleEngine(ParticleType t, int maxParticle = 10000);
    ~ParticuleEngine();

    void drawParticles(QOpenGLShaderProgram * prog);
    void uptadeParticles();
    void generateParticles(float seuil);
    int findUnusedParticle();

    void setParticleType(ParticleType t);
    void setMaxParticle(int nb);

private:
    int lastUsedParticle;
    int maxParticle;
    Particle particleContainer[MAX_PARTICULES];
    QOpenGLBuffer arrayBuffer;
    std::vector<ParticleData> vParticlesData;
    double lastTime;
    ParticleType type;

    void initParticles();
};

#endif // PARTICULESENGINE_H
