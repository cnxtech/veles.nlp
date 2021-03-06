/**
 *
 * .. invisible:
 *     _   _ _____ _     _____ _____
 *
 *    | | | |  ___| |   |  ___/  ___|
 *
 *    | | | | |__ | |   | |__ \ `--.
 *
 *    | | | |  __|| |   |  __| `--. \
 *
 *    \ \_/ / |___| |___| |___/\__/ /
 *
 *     \___/\____/\_____|____/\____/
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *   http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License
 *
 */

#ifndef DISAMBIGUATOR_SETTINGS_INTERFACE
#define DISAMBIGUATOR_SETTINGS_INTERFACE

#include "MorphologicalDictionary.h"
#include "ICRFSettings.h"
#include "IDisambiguator.h"
#include "IFeatureCalculator.h"

namespace Disambiguation
{

using Tools::Language;

class IDisambiguatorSettings : public virtual LinearCRF::ICRFSettings
{
public:
    virtual shared_ptr<IChainTransformer> GetChainTransformer() = 0;
    virtual shared_ptr<IPossibleStateFinder> GetPossibleStateFinder() = 0;
    virtual shared_ptr<IRegularization> GetRegularizator() = 0;
    virtual shared_ptr<RelearnRegularization> GetRelearnRegularizator() = 0;
    virtual shared_ptr<MorphologicalDictionary> GetDictionary() = 0;
    virtual shared_ptr<IFeatureCalculator> GetFeatureCalculator() = 0;

    virtual shared_ptr<DataFunctor> GetTrainingFunctor() = 0;
    virtual shared_ptr<DataFunctor> GetTestFunctor() = 0;

    virtual const string& GetIntermidiateOutputFile() const = 0;
    virtual size_t GetMaxNumberOfIterations() const = 0;
    virtual const string& GetModelFile() const = 0;
    virtual size_t GetPeriodOfTesting() const = 0;
    virtual const string& GetTrainingSetFile() const = 0;
    virtual const string& GetTestSetFile() const = 0;
    virtual const string& GetTokenLabelSetFile() const = 0;
    virtual const string& GetRelearnSetFile() const = 0;
    virtual const string& GetRelearnInputSetFile() const = 0;
    virtual bool IsModelFileBinary() const = 0;

    virtual Language GetLanguage() const = 0;

    virtual shared_ptr<IDisambiguator> GetDisambiguator() = 0;
    virtual shared_ptr<IDisambiguator> ReloadDisambiguator() = 0;
};

}

#endif // DISAMBIGUATOR_SETTINGS_INTERFACE


